export function isValid(s : string) : boolean {
    let st : string[] = [];
    const brackets = {
        '(' : ')',
        '{' : '}',
        '[' : ']'
    }
    for(let i = 0; i < s.length; i++){
        if(s[i] === '(' || s[i] === '{' || s[i] === '[') st.push(s[i]);
        else if(brackets[st.pop()] !== s[i]) return false;
    }

    return true;
}