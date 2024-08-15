# Optimizing Austin's Graveler code

This is a repository with some attempts to optimize Austin's ([ShoddyCast](https://www.youtube.com/@ShoddyCast)) Graveler Soft Lock code (from this [video](https://www.youtube.com/watch?v=M8C8dHQE2Ro)).

## Main Changes

Here are the main changes I made to speed up the code:

- **Removed the storing of non-interesting outcomes:** if we just want to know how many 1's are rolled, why do we keep the amount of 2,3 and 4's
- **Added a break for when we know the rolls can't be better:** This has it's downsides, but at least throuhg testing it seems to perform better. The idea is to check if the next few rolls would be useless, eg: the `maxOnes` is 100 and we have 50 `rolls` missing, but currently we only have 49 hits, it would be a waste of time to continue searching.
- **Changing from Python to a other languages:** Very likely the final bottle neck would be python's interpreter, while I think its possible to make faster code in python than my fastest code, I'm not going to be the one to do it, so I just used other languages I knew could be faster.

## Other Changes

I also made some other changes to make the use of this code more user-friendly... I mean I know its just to see who is fastest, but I wanted to see the code working, not just stare at a blank void waiting for an answer.

- Added a progress report to show the best outcome (so you know your PC didnt crash)
- Added timing code
- Added the amount of rolls as an input

## Languages and notes

I mostly work on `PHP` and `JS`, but I have done my fair share of `C`, `Lua` and `Python` development, so those are the languages I tried out:

- `JS`: Node v18.19.0
  - I ran this on powershell, but you could run it on your browser.
- `PHP`: 8.3.6
  - It kinda takes a bit to start that is not accounted for in the timing, but it isn't enough to change its position.
- `Lua`: 5.4
  - Running on WSL (Window Subsystem for Linux)
- `C`: Don't think C has versions.
  - Compiling and running on WSL
  - To compile run: `gcc -o graveler c-optimized-c.c` (you need to install gcc, [google that](https://www.google.com/search?client=firefox-b-d&q=how+to+install+gcc))
- `Python`: 3.12.4

## Average Times

This are just averages I got from running the codes a few times.

For 1.000.000 rounds:
 - `C`: 1,8s
 - `JS`: 2,5s
 - `Lua`: 10s
 - `PHP`: 12s
 - `Optimized Python`: 41s
 - `Original Python`: 135s

I only ran the fastest codes as I didnt want to leave my PC on for too long for times I wouldnt submit.

For 1.000.000.000 rounds:
- `C`: 1515s

## Fastest run of 1.000.000.000 (Billion) rounds

![FastestRun](https://github.com/lopoi/Graveler-Shoddy/blob/main/best_run.png?raw=true)
