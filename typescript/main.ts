import { TSRun } from "./base_ds_algorithm/trie/trie";
import { AsteroidCollision } from "./leetCode/linked_list/AsteroidCollision";

function main(){
    //AsteroidCollision();
    // const sampleArray = [1, 2, 3, 4, 5];
    // const hap = sampleArray.map(function (unit){
    //     return unit + unit
    // });

    // console.log(hap);

    //TSRun();

    let object = "메뉴1";
    let words = ["메뉴1", "메뉴2", "메뉴3", "메뉴4"];
    // let tmp = words.filter((word: string) =>{
    //     if(word !== '' && 
    //         object !== ''  && 
    //         word.includes(object) === true && 
    //         word[0] === object[0]) {
    //             console.log(word[0]);
    //             console.log(object[0]);
    //             return word;
    //     }
    // });
    //console.log(tmp);
    console.log(words.some((value: string) => value === object));
}
main();