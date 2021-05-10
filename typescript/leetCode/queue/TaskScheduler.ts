export function leastInterval(tasks: string[], n: number): number {
    if (n === 0) return tasks.length;

    let maxTask : number = 0;
    let numpeak : number = 0;
    let m : number = tasks.length;
    let task : Object = {};

    for(let i of tasks){

        task[i] = task[i] ? task[i] + 1 : 1;
        maxTask = Math.max(maxTask, task[i]);
    }
    Object.keys(task).forEach(key => {
        if(task[key] == maxTask) numpeak++;
    });

    return Math.max(m, (maxTask - 1) * (n + 1) + numpeak);
};