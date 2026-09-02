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

## Threat model

`bare-hrtime` is one of the addons Bare compiles into its binary, so it inherits [Bare's threat model](https://github.com/holepunchto/bare/blob/main/docs/threat-model.md). See [`docs/threat-model.md`](docs/threat-model.md) for where this addon sits in it.

## License

Apache-2.0
