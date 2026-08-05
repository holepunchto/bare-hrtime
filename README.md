# bare-hrtime

High-resolution timers for JavaScript.

```
npm i bare-hrtime
```

## Usage

```js
const hrtime = require('bare-hrtime')

hrtime() // returns [seconds, nanoseconds]
hrtime.bigint() // returns nanoseconds
```

## License

Apache-2.0

<!-- bare-refgen:api start -->

## API

### Functions

#### `hrtime(prev?: ArrayLike<number>): [seconds: number, nanoseconds: number]`

Returns the current high-resolution time as a `[seconds, nanoseconds]` tuple. If `prev` (a previous `hrtime()` result) is given, returns the elapsed time since it instead.

**Parameters**

| Parameter | Type                | Default | Description                                                     |
| --------- | ------------------- | ------- | --------------------------------------------------------------- |
| `prev?`   | `ArrayLike<number>` | —       | A previous `hrtime()` result to compute the elapsed time since. |

<!-- bare-refgen:api end -->
