import Qt 4.7

Rectangle {
    width: 300
    height: 300
    Row {
        TrafficLight {
            timerInterval: 2800
        }
        TrafficLight {
            timerInterval: 3000
        }
        TrafficLight {
            timerInterval: 3200
        }
    }
}
