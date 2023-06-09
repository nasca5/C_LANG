/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function (arr, size) {
  let total = [];
  let result = [];
  arr.forEach((data, i) => {
    result.push(data);
    if ((i + 1) % size == 0 || i + 1 == arr.length) {
      total.push(result);
      result = [];
    }
  });
  return total;
};
