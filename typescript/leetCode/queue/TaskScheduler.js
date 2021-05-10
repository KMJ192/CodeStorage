"use strict";
exports.__esModule = true;
exports.leastInterval = void 0;
function leastInterval(tasks, n) {
    if (n === 0)
        return tasks.length;
    var maxTask = 0;
    var numpeak = 0;
    var m = tasks.length;
    var task = {};
    for (var _i = 0, tasks_1 = tasks; _i < tasks_1.length; _i++) {
        var i = tasks_1[_i];
        task[i] = task[i] ? task[i] + 1 : 1;
        maxTask = Math.max(maxTask, task[i]);
    }
    Object.keys(task).forEach(function (key) {
        if (task[key] == maxTask)
            numpeak++;
    });
    return Math.max(m, (maxTask - 1) * (n + 1) + numpeak);
}
exports.leastInterval = leastInterval;
;
