import QtQuick 2.0

Application {
    devicFamily : "cc13x0"

    RfCore {
        signal poweredUp();
        signal poweredDown();
    }

    RfPhy {
        cpePatch : "mce_rfe_patch"

        setupCommand : CMD_PROP_RADIO_DIV {

        }

        frequencyCommand : CMD_FS {

        }
    }

    Pin {
        ioid : 0
        type : Pin.Input
        pull : Pin.PullUp

        onValueChanged : {
            console.log("Pin " + ioid + "value: " + value);
        }
    }

    Pin {
        ioid : 1
        type : Pin.Output
        pull : Pin.PullUp

        onValueChanged : {
            console.log("Pin " + ioid + "value: " + value);
        }
    }

    AdcChannel {
        ioid : 0
        value : 0

        function startSingle() {}

        onValueChanged : {

        }
    }
}
