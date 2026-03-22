Dragon Hunting
==============

A set of experiments for potential solutions to the "Dragon Hunting"
problem, which is detailed elsewhere.

Usage:

1. Put your algorithm in `hunt.cpp`. You'll see some sample algorithms in
the various `huntXX.cpp` files. 

    I'd recommend that you put your algorithm in a separate file and
    copy it over to `hunt.cpp`. That way, you can easily switch algorithms
    without deleting important work.

    Here's one such algorithm, from `hunt00.cpp`.

       bool huntDragon(World& w) {
           for (int i = w.size() - 1; i >= 0; i--) {
               w.note("Looking at farm " + to_string(i));
               if (w.get(i) == DRAGON) {
                   return true;
               } // if
           } // for
           return false;                       // This shouldn't happen
       } // huntDragon(World)

    The `World` class provides the following methods:

    * `get(int i)`: Advance the dragon and check out farm `i`.
    * `note(string msg)`: Prints a message if we're in trace mode.
    * `useOneBasedIndexing()`: Change the indexing model from 0-based
      to 1-based for those who think that way.

2. Run `make`. If all goes well, it should create the executables
`test-hunt` and `trace-hunt`.

3. Run `./test-hunt`. If all goes well, it will run a series of tests,
give you some details on any failed tests, and tell you how many worked.

    Here's sample output using hunt00.cpp.

        $ ./test-hunt
        For n=2, k=0: algorithm failed to find dragon
        For n=4, k=0: algorithm failed to find dragon
        For n=5, k=1: algorithm failed to find dragon
        For n=6, k=0: algorithm failed to find dragon
        For n=6, k=2: algorithm failed because: everything has been burned
        For n=7, k=1: algorithm failed to find dragon
        For n=8, k=0: algorithm failed to find dragon
        ...
        
4. If a test fails, you can trace it with `./trace-hunt n k`, substituting
the appropriate `n` and `k`.

        $ ./trace-hunt 6 0
        Looking at farm 5
        !OOOOO
        01234^
        
        Looking at farm 4
        .!OOOO
        0123^5
        
        Looking at farm 3
        ..!OOO
        012^45
        
        Looking at farm 2
        ...!OO
        01^345
        
        Looking at farm 1
        ....!O
        0^2345
        
        Looking at farm 0
        .....!
        ^12345
        
        The algorithm could not find the dragon.
        The dragon WAS NOT found.

Good luck!
