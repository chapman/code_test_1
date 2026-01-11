#!/bin/bash
# Ralph Wiggum loop runner
#
# Usage: ./run-ralph.sh [max_iterations]
#
# This script runs Claude Code with the /ralph skill to execute
# the task defined in PROMPT.md autonomously.

MAX_ITERATIONS=${1:-20}

echo "Starting Ralph Wiggum loop..."
echo "Max iterations: $MAX_ITERATIONS"
echo ""
echo "To run the loop, use one of these methods:"
echo ""
echo "1. Interactive mode (recommended):"
echo "   claude"
echo "   Then type: /ralph"
echo ""
echo "2. Headless mode:"
echo "   echo '/ralph' | claude"
echo ""
echo "The loop will read PROMPT.md and execute tasks from TODO.md"
echo "until completion or max iterations ($MAX_ITERATIONS) is reached."
echo ""
echo "Monitor progress in TODO.md - tasks will be marked [x] as they complete."
echo "The loop stops when it outputs: <promise>COMPLETE</promise>"
