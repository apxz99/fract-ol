#!/bin/bash

VALID_TESTS=(
"./fractol mandelbrot"

"./fractol julia 0 0"
"./fractol julia 0.285 0"
"./fractol julia -0.8 0.156"

"./fractol julia .5 .5"
"./fractol julia -.5 .5"
"./fractol julia +.5 -.5"

"./fractol julia 123. 456."
"./fractol julia -.123 +.456"

"./fractol julia 1 1"
"./fractol julia -1 -1"
"./fractol julia +1 -1"

"./fractol julia .123 .456"
"./fractol julia -.123 -.456"
"./fractol julia +.123 +.456"

"./fractol julia 123.456 -789.012"
"./fractol julia 0000.0123 0456"

"./fractol julia 999999999999999999999 0"
"./fractol julia -999999999999999999999 0"
)

INVALID_TESTS=(

"./fractol"
"./fractol julia"
"./fractol julia 1"
"./fractol julia 1 2 3"
"./fractol mandelbrot 1"

"./fractol julia a b"
"./fractol julia hello world"

"./fractol julia 1..2 0"
"./fractol julia 0 1..2"

"./fractol julia --1 0"
"./fractol julia ++1 0"
"./fractol julia +-1 0"
"./fractol julia -+1 0"

"./fractol julia .+5 0"
"./fractol julia .-5 0"
"./fractol julia . 0"
"./fractol julia -. 0"
"./fractol julia +. 0"

"./fractol julia ..5 0"
"./fractol julia ... 0"

"./fractol julia nan 0"
"./fractol julia inf 0"
"./fractol julia 1e309 0"

"./fractol test"
"./fractol jul"
"./fractol fractal"

"./fractol julia \"\" \"\""
"./fractol julia \"\" 0"
"./fractol julia 0 \"\""
)

run_valid() {
    echo "=========================="
    echo " FRACT-OL VALID TESTS"
    echo "=========================="

    for t in "${VALID_TESTS[@]}"; do
        echo
        echo "RUNNING: $t"
        echo "Press ESC to close window..."
        eval $t
    done
}

run_invalid() {
    echo "=========================="
    echo " FRACT-OL INVALID TESTS"
    echo "=========================="

    for t in "${INVALID_TESTS[@]}"; do
        echo
        echo "RUNNING: $t"
        eval $t
        echo "Should show usage and exit"
    done
}

echo
echo "Choose test mode:"
echo "1) Valid tests"
echo "2) Invalid tests"
echo "3) All tests"
echo

read -p "Enter choice: " choice

case $choice in
1)
    run_valid
    ;;
2)
    run_invalid
    ;;
3)
    run_valid
    run_invalid
    ;;
*)
    echo "Invalid choice"
    ;;
esac

echo
echo "All tests finished."