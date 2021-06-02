function examOne(){
    let innerText : string = "내부값";
    return {
        setText(cText) {
            innerText = cText;
        },
        getText(){
            console.log(innerText)
        }
    }
}

export function closureFunc(){
    const test1 = examOne();
    const test2 = examOne();
    const test3 = examOne();

    test1.getText();
    test2.getText();
    test3.getText();

    test1.setText("test2");
    test2.setText("test4");
    test3.setText("test6");

    test1.getText();
    test2.getText();
    test3.getText();
}