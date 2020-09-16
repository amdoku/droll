EBNF should parse things like:
1d6
2 * 3d6
3 + 5
1 + 1d4 + 3d6

Edge cases it should parse as well:
0d6
0 * 1d4
<empty input; should be 0>

EBNF:

dice    = expression 'd' numbers
number  = '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
numbers = number | number numbers
diceExpression = numbers '+' dice | numbers '-' dice
diceFactor = numbers '*' dice | numbers '/' dice
numberExpression = numbers | numbers '+' numbers | numbers '-' numbers
numberFactor = numbers '*' numbers | numbers '/' numbers
expression = diceExpression  expression | diceFactor expression | numberExpression expression | numberFactor expression | <empty>

