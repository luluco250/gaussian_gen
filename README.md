# Gaussian Generator

```gaussian_gen``` is a small program generates a sequence of numbers using
gaussian distribution. Useful for defining constants in shaders.

Usage: ```gaussian_gen <samples> <sigma>```
* ```samples```: How many samples/taps to generate, expects an integer.
* ```sigma```: The sigma value used in the gaussian function, expects a decimal/real.

For example:

```gaussian_gen 7 1.5``` -> ```0.265962 0.212965 0.109340 0.035994 0.007597 0.001028 0.000089```

The gaussian blur algorithm used come from [here](https://en.wikipedia.org/wiki/Gaussian_blur#Mathematics) (Wikipedia).
