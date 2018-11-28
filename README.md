# f1telemetry

C++ Telemetry tools for the Formula 1 game F12018 by CodeMasters

## Background

There was a time when I was pretty good at C++. But that was a long time ago.

I wanted to work on a simple project that would let me re-learn some of those long forgotten C++ concepts, so I decided to combine some of my passions (Formula 1, and F1 gaming) to help me along this journey.

And man, what a journey. I've been away from C++ for far too long... I'm sure some of you experts would have been bashing your head against the desk watching me limp through this code.

I'm sure I did things wrong, and I encourage anybody who knows this world better than me to provide helpful advice.

## F12018 by Codemasters

So F12018 is a pretty awesome game. Admittedly it is not the best SIM out there... if you're looking for real authenticity I'm confident you'll do better looking into R-Factor or some of the other real sims. But for me F12018 is the right amount of fun vs real physics.

From a technical perspective the game is interesting because it broadcasts a motherload of data about your races and laps via UDP. CodeMasters was kind enough to provide the spec for the format here:

https://forums.codemasters.com/discussion/136948/f1-2018-udp-specification

## What is f1telemetry?

This repo has two programs to help you collect and extract the f1 telemetry data that is broadcast by the F12018 game.

### Building

I addition to learning C++, I wanted to get comfortable with some of the latest/greatest in the world of toolchains. I discovered [bazel](https://bazel.build/) and decided it would probably make my life a bit easier and I could learn something new as well. So I used bazel

To build the two apps, you run the following bazel commands:

```
% cd f1telemetry
% bazel build //capture
% bazel build //extract
```

### Setting up the F1 Game

In order to capture data, you'll need to set up your F12018 game to broadcast. I have a PS4, so hopefully configuration on other platforms is similar:

* Run the F12018 Game
* From the main menu, open "Game Options"
* Open Settings -> Telemetry Settings
* Turn UDP Telemetry On

Most of the rest of the configuration settings can remain the same, unless there is something different about your home network.

If you want more detailed telemetry, you can up the UDP send rate. Be warned, the higher the send rate, the larger your capture files will be. For example, I tried 60Hz, and one single lap of a track game me almost 30MB.

After configuring the game properly, it will always broadcast UDP race data on your local network.

### Capturing Data

To capture data, run a command like this:

```
% ./bazel-bin/capture/capture -p 20777 -o my_capture_file
```

Captured data is in the raw form spat out by the F1 game: packed UDP bytes. The capture server doesn't do anything really smart, it just pipes the data to a file.

### Extracting Data

The extract command converts the captured files to CSV so you can analyze and process them.

To extract telemetry data, run the following command:

```
% ./bazel-bin/capture/capture -i my_capture_file -o my_telemetry_file.csv
```

## Known Issues

* The extract program hardcodes 20 drivers. Bad. Bad. I didn't spend the time to figure out how to do this properly, and the extract code doesn't work with time trials currently, only races with 20 drivers. If anybody wants to take a look and help me figure it out, I'd be very appreciative!

## Feedback

Let me know if you gave the code a whirl and how it worked out. Feel free to give me feedback, C++ tips, general life advice, or whatever.
