/**
 * Returns the current high-resolution time as a `[seconds, nanoseconds]` tuple. If `prev` (a
 * previous `hrtime()` result) is given, returns the elapsed time since it instead.
 * @param prev - A previous `hrtime()` result to compute the elapsed time since.
 */
declare function hrtime(prev?: ArrayLike<number>): [seconds: number, nanoseconds: number]

declare namespace hrtime {
  /**
   * Returns the current high-resolution time in nanoseconds as a `bigint`. The value is relative
   * to an arbitrary point in the past and is only meaningful when compared against another
   * reading.
   */
  export function bigint(): bigint
}

export = hrtime
