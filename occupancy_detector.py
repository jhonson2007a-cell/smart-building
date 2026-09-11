import cv2
import json
import time
import paho.mqtt.client as mqtt
from ultralytics import YOLO

# --- MQTT Configuration ---
MQTT_BROKER = "broker.hivemq.com"
MQTT_PORT = 1883
MQTT_TOPIC = "ecozone/campus/room_101/occupancy"

client = mqtt.Client()
client.connect(MQTT_BROKER, MQTT_PORT, 60)

# --- Load Lightweight YOLOv8 Model ---
model = YOLO("yolov8n.pt")  # Nano version for fast edge processing

cap = cv2.VideoCapture(0)  # Use 0 for WebCam or RTSP URL for CCTV

print("EcoZone AI Occupancy Monitor Started...")

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break

    # Perform inference (class 0 is 'person' in COCO dataset)
    results = model(frame, classes=[0], conf=0.4, verbose=False)
    
    # Count detected people
    person_count = len(results[0].boxes)

    # Payload creation
    payload = {
        "room_id": "Room_101",
        "occupancy_count": person_count,
        "timestamp": int(time.time())
    }

    # Publish MQTT message
    client.publish(MQTT_TOPIC, json.dumps(payload))
    print(f"Published: {person_count} occupants in Room 101")

    # Optional display
    annotated_frame = results[0].plot()
    cv2.putText(annotated_frame, f"Occupants: {person_count}", (20, 50),
                cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
    cv2.imshow("EcoZone Edge AI Monitor", annotated_frame)

    if cv2.waitKey(1000) & 0xFF == ord('q'):  # Publish every 1 second
        break

cap.release()
cv2.destroyAllWindows()
