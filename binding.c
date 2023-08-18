#include <assert.h>
#include <bare.h>
#include <js.h>
#include <uv.h>

static js_value_t *
bare_hrtime (js_env_t *env, js_callback_info_t *info) {
  int err;

  js_value_t *argv[2];
  size_t argc = 2;

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  uint32_t *next;
  err = js_get_typedarray_info(env, argv[0], NULL, (void **) &next, NULL, NULL, NULL);
  assert(err == 0);

  uint32_t *prev;
  err = js_get_typedarray_info(env, argv[1], NULL, (void **) &prev, NULL, NULL, NULL);
  assert(err == 0);

  uint64_t then = prev[0] * 1e9 + prev[1];
  uint64_t now = uv_hrtime() - then;

  next[0] = now / ((uint32_t) 1e9);
  next[1] = now % ((uint32_t) 1e9);

  return argv[0];
}

static js_value_t *
bare_hrtime_bigint (js_env_t *env, js_callback_info_t *info) {
  int err;

  js_value_t *result;
  err = js_create_bigint_uint64(env, uv_hrtime(), &result);
  assert(err == 0);

  return result;
}

static js_value_t *
init (js_env_t *env, js_value_t *exports) {
  {
    js_value_t *val;
    js_create_function(env, "hrtime", -1, bare_hrtime, NULL, &val);
    js_set_named_property(env, exports, "hrtime", val);
  }
  {
    js_value_t *val;
    js_create_function(env, "hrtime", -1, bare_hrtime_bigint, NULL, &val);
    js_set_named_property(env, exports, "bigint", val);
  }

  return exports;
}

BARE_MODULE(bare_hrtime, init)
