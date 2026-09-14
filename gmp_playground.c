#include <stdio.h>
#include <gmp.h>

int main() {
  /* allocate space, initialize its value to 0. */
  mpz_t a, b;
  mpz_init(a);
  mpz_init(b);

  /* set values */
  mpz_set(a, b);
  mpz_set_si(a, -100);
  mpz_set_ui(a, 100);
  mpz_set_d(a, 123.0);

  /* allocate space and set value in one shot. */
  mpz_init_set_str(a, "12345678987654321", 10); /* base 10 */
  mpz_init_set(a, b);
  mpz_init_set_si(a, -100);
  mpz_init_set_ui(a, 100);
  mpz_init_set_d(a, 123.0);

  /* conversion, if OP is too big, the result maybe meaningless. */
  mpz_set(a, -100);
  long si = mpz_get_si(a); /* si = -100 */
  mpz_set(a, 100);
  unsigned long ui = mpz_get_ui(a); /* ui = 100 */
  mpz_set_d(a, 123.0);
  double d = mpz_get_d(a); /* d = 123.0 */
  char result[100];
  mpz_get_str(result, 10, a);

  /* arithmetic */
  mpz_t c;
  mpz_add(c, a, b); /* c = a + b */
  mpz_add_ui(c, a, 10);
  mpz_sub(c, a, b); /* c = a - b */
  mpz_sub_ui(c, a, 10);
  mpz_ui_sub(c, 10, a);
  mpz_mul(c, a, b); /* c = a * b */
  mpz_mul_si(c, a, -100);
  mpz_mul_ui(c, a, 100);
  mpz_addmul(c, a, b); /* c = c + a * b */
  mpz_addmul_ui(c, a, 100);
  mpz_submul(c, a, b); /* c = c - a * b */
  mpz_submul(c, a, 100);
  mpz_neg(c, a); /* c = -a */
  mpz_abs(c, a); /* c = |a| */

  /* formatted input & output */
  gmp_scanf("%Zd", c);
  gmp_printf("%Zd\n", c);

  /* clear memory */
  mpz_clear(a);
  mpz_clear(b);
  mpz_clear(c);
  return 0;
}