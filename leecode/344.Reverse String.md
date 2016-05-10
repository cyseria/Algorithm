# 344. Reverse String

> Write a function that takes a string as input and returns the string reversed.
  Example:
  Given s = "hello", return "olleh".



Answer:

```
/**
 * @param {string} s
 * @return {string}
 */
var reverseString = function(s) {
    if (s.length === 0) {
        return "";
    } else {
        return s.split("").reverse().join("");
    }
};
```