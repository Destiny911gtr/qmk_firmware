#pragma once

#include "encoder.c"

void encoder_action_cursor(bool clockwise);
void encoder_action_mediatrack(bool clockwise);
void encoder_action_navword(bool clockwise);
void encoder_action_desktop(bool clockwise);
void encoder_action_rgb_speed(bool clockwise);
void encoder_action_rgb_hue(bool clockwise);
void encoder_action_rgb_saturation(bool clockwise);
void encoder_action_rgb_brightness(bool clockwise);
void encoder_action_rgb_mode(bool clockwise);