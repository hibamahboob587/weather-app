#ifndef ALERT_H
#define ALERT_H

#include <stdlib.h>
#include <jansson.h>
#include <stdio.h>
void FogAlert(json_t *visibility);
void TemperatureAlert(json_t *temperature) ;
void HurricaneAlert(json_t *speed) ;
void RainAlert(json_t *percent);
void sunriseAlert() ;
void sunsetAlert() ;
#endif /* EMAIL_ALERTS_H */
