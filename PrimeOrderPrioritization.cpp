/*

Prime Order Prioritization:

Amazon is planning to release a new order prioritization algorithm to optimize fulfilling Prime deliveries on time.
All orders (Prime or otherwise) are given an alphanumeric ID code. However, Prime orders are given additional metadata that consists of a space delimited list of 
lowercase English letters, whereas non-Prime orders are given metadata that consists only of a space delimited string of positive integers.
Each order is therefore defined as their alphanumeric id code, followed by a space, followed by their space delimited metadata.
You have been tasked with sorting a list of all orders in the order queue to assist in prioritization of fulfillment. They should be sorted according to the following order:

1. The Prime orders should be returned first, sorted by lexicographic sort of the alphabetic metadata.
2. Only in the case of ties, the identifier should be used as a backup sort.
3. The remaining non-Prime orders must all come after, in the original order they were given in the input.
Write a function or method to sort the orders according to this system.

Input:
The input to the function/method consists of one argument:
orderList, a list of strings representing all orders.

Output:
Return a list of strings representing the correctly prioritized orders according to this system.

Constraints:
0<= number of orders <= 10^3

Note:
The order identifier consists of only lower case English characters and numbers. 
Sort for tie breaks should use ASCII value - as an example, the order identifier 'a1' should come before order identifier 'aa'

Example1:

*/
