<?php

/*
 * Complete the 'changeBits' function below.
 *
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 *  3. STRING_ARRAY queries
 */

function changeBits($a, $b, $queries) {
  $aa = gmp_init($a, 2);
  $bb = gmp_init($b, 2);

  foreach ($queries as $query)
  {
    @list($command, $pos, $value) = @explode(" ", $query);

    if ($command == "get_c")
    {
      $cc = gmp_add($aa, $bb);
      echo gmp_testbit($cc, $pos) ? "1" : "0";
    }
    else if ($command == "set_a")
      gmp_setbit($aa, $pos, $value == 1);
    else // set_b
      gmp_setbit($bb, $pos, $value == 1);
  }
}

$first_multiple_input = explode(' ', rtrim(fgets(STDIN)));

$ab_size = intval($first_multiple_input[0]);

$queries_size = intval($first_multiple_input[1]);

$a = rtrim(fgets(STDIN), "\r\n");

$b = rtrim(fgets(STDIN), "\r\n");

$queries = array();

for ($i = 0; $i < $queries_size; $i++) {
    $queries_item = rtrim(fgets(STDIN), "\r\n");
    $queries[] = $queries_item;
}

changeBits($a, $b, $queries);
