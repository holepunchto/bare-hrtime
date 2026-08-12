/**
 * Returns the current high-resolution time as a `[seconds, nanoseconds]` tuple. If `prev` (a
 * previous `hrtime()` result) is given, returns the elapsed time since it instead.
 * @param prev - A previous `hrtime()` result to compute the elapsed time since.
 */
declare function hrtime(prev?: ArrayLike<number>): [seconds: number, nanoseconds: number]

declare namespace hrtime {
  export function bigint(): bigint
}

export = hrtime
