# Threat model

## What this is

`bare-hrtime` is compiled into Bare. It is listed in `src/builtins.json`, so every Bare process has it. That holds whether or not the process sealed, and no code has to load anything to reach it.

So this addon is part of Bare, and [Bare's threat model](https://github.com/holepunchto/bare/blob/main/docs/threat-model.md) covers it. Read that one first. This one only says where this addon sits in it.

## What it inherits

- **The promise.** Bare promises a sealed process gets no new native code. This addon is native code that is already in, so the seal neither adds it nor takes it away.
- **The attacker.** Untrusted JavaScript in a sealed process. It writes what it likes, runs on as many threads as it wants, and calls anything it can reach in any order and all at once. It can reach all of this addon.
- **The trust.** This addon is trusted, because Bare compiles it in. Whatever you compile in is your security policy, and this is one of the things you picked.
- **The walls.** The same table applies. A thread is not a wall and neither is a realm, so nothing here gets to assume it is alone.
- **The rules.** What Bare says to report, and what Bare says is not a bug, is the same here.

## What counts

- **Counts:** `binding.c` and the JavaScript that ships with it. Sealed JavaScript reaches all of it without loading a thing.
- **Does not count:** tests, benchmarks, and scratch code.

## What this addon adds

A clock. It is monotonic and it counts nanoseconds. That is all it does.

## Where the risk is

Bare's document says fast timers plus `SharedArrayBuffer` give side channels against anything in the same address space, the embedder's own app included, and lists that under what still works after the seal. This addon is one of those fast timers.

A precise clock is the point, so precision is not a bug. Making it coarser here would buy nothing either, because the engine has its own timers and `SharedArrayBuffer` is always on. If timing side channels matter to you, use an OS sandbox or a separate process, which is what Bare says already.

There is barely any C here, and what there is reads a clock into a fixed buffer.

## What to report

- Memory bugs in `binding.c` that JavaScript can reach
- Anything on Bare's report list

Not a bug: that the clock is precise, or that someone times something with it.
