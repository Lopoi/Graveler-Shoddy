<?php

$start = microtime(true);
$rounds = 231;
$rolls = 0;
$maxRolls = isset($argv[1]) ? (int)$argv[1] : 100;
echo "Running for " . $maxRolls . " rolls\n";
$ones = 0;
$maxOnes = 0;
$items = [1, 2, 3, 4];
while ($ones < 177 && $rolls < $maxRolls) {
    $ones = 0;
    for ($i = 0; $i < $rounds; $i++) {
        $roll = array_rand($items);
        if ($roll == 1) {
            $ones++;
            if ($ones + ($rounds - $i) < $maxOnes) {
                break;
            }
        }
    }
    $rolls++;
    if ($ones > $maxOnes) {
        echo $ones . "\n";
        $maxOnes = $ones;
    }
}
$end = microtime(true);
echo "Time: " . ($end - $start) . "\n";
echo "Best: " . $maxOnes . "\n";
