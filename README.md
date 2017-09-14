# TruthTableC
Truth Table by Iterative function and Recursive function in C Language<br>
You can have a try in your browser at: https://ideone.com/93uSIu

## Recursive Function
The important thing you should be awareness in `Recursive Function` is that "When does the recursive ends?"<br>
How I approached to this problem is that I could fill in from the first of the array, beginning from 0.<br>
So, the first call will be like this, with the parameter `finish = 3` for example:

| Pos | 0 | 1 | 2 |
| :---: | :---: | :---: | :---: |
| Value | 0 |  |  | 

And then you can call that function recursively(2nd call), with `pos` parameter increased.

| Pos | 0 | 1 | 2 |
| :---: | :---: | :---: | :---: |
| Value | 0 | 0 |  | 

One more call(3rd call) will make the `pos` equals `finish-1`

| Pos | 0 | 1 | 2 |
| :---: | :---: | :---: | :---: |
| Value | 0 | 0 | 0 | 

One more call(4th call) will make the `pos` equals `finish`. Finally, the end condition was made(`pos` equals `finish` means that has no more space to fill in). We can print it, and then by the call stack, we could go back to the last call (3rd call). And here comes your 5th call.

| Pos | 0 | 1 | 2 |
| :---: | :---: | :---: | :---: |
| Value | 0 | 0 | 1 | 

6th call will be `pos` equals `finish`<br>
So we can print it, and call stack will lead you to go back to 2nd call and function will fill `1` to `pos=1`

| Pos | 0 | 1 | 2 |
| :---: | :---: | :---: | :---: |
| Value | 0 | 1 |  | 

Now you can guess what will happen next.

## Iterative function
| Case # | 2 | 1 | 0 | Decimal
| :---: | :---: | :---: | :---: | :---: |
| #1 | 0 | 0 | 0 | 0 |
| #2 | 0 | 0 | 1 | 1 |
| #3 | 0 | 1 | 0 | 2 |
| #4 | 0 | 1 | 1 | 3 |
| #5 | 1 | 0 | 0 | 4 |
| #6 | 1 | 0 | 1 | 5 |
| #7 | 1 | 1 | 0 | 6 |
| #8 | 1 | 1 | 1 | 7 |

Total cases will be 2^n, and you can solve this problem easily by converting decimal number to binary number.
