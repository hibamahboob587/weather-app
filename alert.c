#include <stdio.h>
#include <curl/curl.h>
#include "alert.h"
#include <stdlib.h>
#include <jansson.h>
void RainAlert(json_t *percent){
char command[256];
    snprintf(command, sizeof(command), "notify-send 'Rain Alert' ");
    system(command);
    char email_command[1024];
    snprintf(email_command, sizeof(email_command),
             "echo -e 'From: abc581338@gmail.com\nTo: hibamahboob11@gmail.com\nSubject: RAIN ALERT\n\n high chance of rain\n' | "
             "curl --ssl-reqd --url 'smtps://smtp.gmail.com:465' "
             "-u ' abc581338@gmail.com : mmps uhca muxa nmcy ' " // Use -u for concise authentication
             "--mail-from 'abc581338@gmail.com' "
             "--mail-rcpt 'hibamahboob11@gmail.com' "
             "--upload-file -" // Remove --mail-auth for OAuth 2.0
             );
    system(email_command);
}

void FogAlert(json_t *visibility){
 char command[256];
    snprintf(command, sizeof(command), "notify-send 'FOG Alert' 'Drive safe. \n'");
    system(command);
    char email_command[1024];
    snprintf(email_command, sizeof(email_command),
             "echo -e 'From: abc581338@gmail.com\nTo: hibamahboob11@gmail.com\nSubject: FOG ALERT\n\nDrive safe its foggy outside\n' | "
             "curl --ssl-reqd --url 'smtps://smtp.gmail.com:465' "
             "-u ' abc581338@gmail.com : mmps uhca muxa nmcy ' " // Use -u for concise authentication
             "--mail-from 'abc581338@gmail.com' "
             "--mail-rcpt 'hibamahboob11@gmail.com' "
             "--upload-file -" // Remove --mail-auth for OAuth 2.0
             );
    system(email_command);
}


void HurricaneAlert(json_t *speed){
double wind_speed = json_real_value(speed);
char command[256];
    snprintf(command, sizeof(command), "notify-send 'Hurricane Alert' 'Current wind speed: %.2f\n warmer than usual'", wind_speed);
    system(command);
    char email_command[1024];
    snprintf(email_command, sizeof(email_command),
             "echo -e 'From: abc581338@gmail.com\nTo: hibamahboob11@gmail.com\nSubject: HURRICANE Alert\n\n wind speed :%.2f' | "
             "curl --ssl-reqd --url 'smtps://smtp.gmail.com:465' "
             "-u ' abc581338@gmail.com : mmps uhca muxa nmcy ' " // Use -u for concise authentication
             "--mail-from 'abc581338@gmail.com' "
             "--mail-rcpt 'hibamahboob11@gmail.com' "
             "--upload-file -", // Remove --mail-auth for OAuth 2.0
             wind_speed);
    system(email_command);
}


void TemperatureAlert(json_t *temperature) {
    double temp_value = json_real_value(temperature) - 273.15; // Extract temperature value
    char command[256];
    snprintf(command, sizeof(command), "notify-send 'Temperature Alert' 'Current temperature: %.2f°C \n warmer than usual'", temp_value);
    system(command);
    char email_command[1024];
    snprintf(email_command, sizeof(email_command),
             "echo -e 'From: abc581338@gmail.com\nTo: hibamahboob11@gmail.com\nSubject: High Temperature Alert\n\nTemperature is above threshold: %.2f°C' | "
             "curl --ssl-reqd --url 'smtps://smtp.gmail.com:465' "
             "-u ' abc581338@gmail.com : mmps uhca muxa nmcy ' " // Use -u for concise authentication
             "--mail-from 'abc581338@gmail.com' "
             "--mail-rcpt 'hibamahboob11@gmail.com' "
             "--upload-file -", // Remove --mail-auth for OAuth 2.0
             temp_value);
    system(email_command);
}

void sunriseAlert() {

    char command[256];
    snprintf(command, sizeof(command), "notify-send 'SUNRISE Alert' 'good morning! \n'");
    system(command);
    char email_command[1024];
    snprintf(email_command, sizeof(email_command),
             "echo -e 'From: abc581338@gmail.com\nTo: hibamahboob11@gmail.com\nSubject: SUNRISE ALERT\n\ngood morning!\n' | "
             "curl --ssl-reqd --url 'smtps://smtp.gmail.com:465' "
             "-u ' abc581338@gmail.com : mmps uhca muxa nmcy ' " // Use -u for concise authentication
             "--mail-from 'abc581338@gmail.com' "
             "--mail-rcpt 'hibamahboob11@gmail.com' "
             "--upload-file -" // Remove --mail-auth for OAuth 2.0
             );
    system(email_command);
}

void sunsetAlert() {

    char command[256];
    snprintf(command, sizeof(command), "notify-send 'SUNSET Alert' 'goodevening!\n'");
    system(command);
    char email_command[1024];
    snprintf(email_command, sizeof(email_command),
             "echo -e 'From: abc581338@gmail.com\nTo: hibamahboob11@gmail.com\nSubject: SUNSET ALERT\n\ngood evening!\n' | "
             "curl --ssl-reqd --url 'smtps://smtp.gmail.com:465' "
             "-u ' abc581338@gmail.com :  mmps uhca muxa nmcy' " // Use -u for concise authentication
             "--mail-from 'abc581338@gmail.com' "
             "--mail-rcpt 'hibamahboob11@gmail.com' "
             "--upload-file -" // Remove --mail-auth for OAuth 2.0
             );
    system(email_command);
}



