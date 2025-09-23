#include "conversion.h"
#include <stdio.h>

float *
km_to_miles_1_svc(conversion_args *argp, struct svc_req *rqstp)
{
    static float result;
    result = argp->value * 0.621371;
    printf("Conversion: %.2f km = %.2f miles\n", argp->value, result);
    return &result;
}

float *
celsius_to_fahrenheit_1_svc(conversion_args *argp, struct svc_req *rqstp)
{
    static float result;
    result = (argp->value * 9/5) + 32;
    printf("Conversion: %.2f°C = %.2f°F\n", argp->value, result);
    return &result;
}
