# Arduino Robot Sketch

This is an old Arduino project.

It is a simple obstacle-avoiding robot sketch. It controls two motors, reads
from an ultrasonic-style trigger/echo distance sensor, and switches behavior
based on whether something is too close.

## What it appears to do

- Sets up two motor channels:
  - Motor A direction pins: `12`, `13`
  - Motor A speed/PWM pin: `10`
  - Motor B direction pins: `2`, `6`
  - Motor B speed/PWM pin: `3`
- Sets up a distance sensor:
  - Trigger pin: `4`
  - Echo pin: `7`
- Runs both motors at full speed using PWM value `255`.
- Moves forward by default.
- Sends a trigger pulse and measures the echo pulse with `pulseIn`.
- If the measured echo duration is less than `1000`, treats that as "too close"
  and spins in place.
- Otherwise, continues moving forward.
