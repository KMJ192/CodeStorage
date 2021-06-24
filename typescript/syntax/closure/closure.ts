const global = (function() {
    let innerText : string = "innerText";
    function examOne(): [string, (cText: string) => void]{
        const setText = (cText: string) => {
            innerText = cText;
        }
        return [innerText, setText];
    }
    return {
        examOne
    }
})();
export function closureFunc(){
    const [state, setText] = global.examOne();
    
    setText("2");
    console.log(state);
}