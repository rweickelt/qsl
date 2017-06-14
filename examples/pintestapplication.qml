import QtQuick 2.0
import qsl 1.0

QslApplication {

    Timer {
        id : timer
        repeat: true
        running: true
        interval: 1000

        onTriggered: {
            if (led1.value === 1)
                led1.value = 0;
            else
                led1.value = 1;
        }
    }

    Pin {
        id : led1
        type : "output"
        ioid: 6

        onValueChanged: {
            console.log("led1 : " + value);
        }
    }

}
