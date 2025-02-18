
// TODO: Implement this.
// Inspired from Table Lamp.
// In the lamp, if you tap and release quickly, it changes the light color., 
// If you tap and hold, it ill increase the brightness.., however, if you release and tap and hold, it decrease the brightness., 
// and once you release for some time in increasing/decreasing mode, it goes back to color changing mode.


// TODO: Short Press, Long press , double press, press and hold button functionality in 
// Arduino.


// Potential Algorithm:
// WIP

/*


if button is pressed:
	set direction = !brightness; // toggle brightness direction. // FIXME
	start timer;

timer expires:
	if button is still pressed:
		long press state = true;
		brightness += (Brightness step size * direction)
		change_lamp_brightness(brightness)
		if(
	else
		Button is not pressed any more., 
		if we were in long press state
			stop the timer
			do noting much to lamp brightness as user has set the desired brightness
		else
			stop the timer
			user has just pressed and released the touch button so change color
			

TODO: Create proper state machine based system
Easy to understand and easy to implement
*/