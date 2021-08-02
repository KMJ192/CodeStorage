import { AsteroidCollision } from "./leetCode/linked_list/AsteroidCollision";

function main(){
    //AsteroidCollision();
    const sampleArray = [1, 2, 3, 4, 5];
    const hap = sampleArray.map(function (unit){
        return unit + unit
    });

    console.log(hap);

}
main();