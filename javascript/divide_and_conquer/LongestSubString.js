var longestSubstring = function(s, k) {
    
    
    const frequency = new Array(26).fill(0);
    
    for(let i = 0; i < s.length; i++) {
        const asciiChar = s[i].charCodeAt(0) - 'a'.charCodeAt(0);
        
        frequency[asciiChar]++;
    }
    
    

    let valid = true;
    let start = 0;
    let max = -Infinity;

    for(let end = 0; end < s.length; end++) {
        const asciiChar = s[end].charCodeAt(0) - 'a'.charCodeAt(0);
        
        if(frequency[asciiChar] < k) {
            let substr = s.substring(start, end)
            max = Math.max(max, longestSubstring(substr, k));
            start = end + 1;
            valid = false;
        }
    }
    if(valid) return s.length;
    
    return Math.max(max, longestSubstring(s.substring(start), k));
}
