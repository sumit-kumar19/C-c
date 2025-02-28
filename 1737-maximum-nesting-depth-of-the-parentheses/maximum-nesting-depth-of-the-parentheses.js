/**
 * @param {string} s
 * @return {number}
 */
var maxDepth = function(s) {
    let counter=0,maxi=0;
   
    s.split('').forEach(char => {
        if (char === '(') {
            counter++;
            maxi = Math.max(maxi, counter);
        } else if (char === ')') {
            counter--;
        }
    });
    return maxi
};