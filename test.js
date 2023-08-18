const test = require('brittle')
const hrtime = require('.')

test('basic', (t) => {
  const fst = hrtime()
  const snd = hrtime(fst)
  t.comment(fst, snd)
})

test('bigint', (t) => {
  t.comment(hrtime.bigint())
})
