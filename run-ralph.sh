#!/bin/bash
# Ralph Wiggum loop runner

MAX_ITERATIONS=${1:-20}
PROMPT_FILE=${2:-PROMPT.md}
iteration=0

echo "Starting Ralph Wiggum loop..."
echo "Max iterations: $MAX_ITERATIONS"
echo "Prompt file: $PROMPT_FILE"
echo ""

while [ $iteration -lt $MAX_ITERATIONS ]; do
    iteration=$((iteration + 1))
    echo "=== Iteration $iteration/$MAX_ITERATIONS ==="

    # Feed the prompt to claude-code
    output=$(cat "$PROMPT_FILE" | claude-code)
    echo "$output"

    # Check for completion promise
    if echo "$output" | grep -q "<promise>COMPLETE</promise>"; then
        echo ""
        echo "✓ Task completed successfully!"
        exit 0
    fi

    echo ""
    sleep 2  # Brief pause between iterations
done

echo "⚠ Max iterations reached without completion"
exit 1
