/**
 * 2703. Return Length of Arguments Passed
 * Write a function argumentsLength that returns the count of arguments passed to it.
 * 
 * Constraints:
 * args is a valid JSON array
 * 0 <= args.length <= 100
 */

/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    return args.length;
};

/**
 * argumentsLength(1, 2, 3); // 3
 */