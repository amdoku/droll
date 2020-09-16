# Notes about the language of DnD style dice rolls

### EBNF should parse things like
 - `1d6`
 - `2 * 3d6`
 - `3 + 5`
 - `1 + 1d4 + 3d6`
 - `9d100`

### Edge cases it should parse as well:
 - `0d6` (should be `0`)
 - `0 * 1d4` (should be `0`)
 - `\` (empty input; should be `0`)
 
### Unsupported cases
 - `4d0`
 - `1d1`

#### EBNF:
```
dice    = numbers 'd' dizeSize
diceSize = ('2' | '3' | '4' | '5' | '6' | '7' | '8' | '9') numbers
positiveNumber = '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
positiveNumbers = positiveNumber number | postiveNumber
number  = '0' | positiveNumbers
numbers = number | number numbers

diceExpression = numbers '+' dice | numbers '-' dice
diceFactor = numbers '*' dice | numbers '/' dice
numberExpression = numbers | numbers '+' numbers | numbers '-' numbers
numberFactor = numbers '*' numbers | numbers '/' numbers

expression = diceExpression  expression | diceFactor expression | numberExpression expression | numberFactor expression | <empty>
```
