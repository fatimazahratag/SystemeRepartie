struct conversion_args {
    float value;
};

program CONVERSION_PROG {
    version CONVERSION_VERS {
        float KM_TO_MILES(conversion_args) = 1;
        float CELSIUS_TO_FAHRENHEIT(conversion_args) = 2;
    } = 1;
} = 0x20000002;

