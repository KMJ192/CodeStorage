const name = {
    firstName: "Moses",
    lastName: "Kim",
  };
  
  function printOutMyName(role, salary, anatomy, char) {
    console.log(
      `${this.firstName} ${this.lastName} has salary of $${salary}, is a ${anatomy}, and has a role of ${role} and ${char}`
    );
  }
  
  Function.prototype.myBinding = function (...args) {
    const obj = this;
    const rest = args.slice(1);
  
    return function (...args2) {
      obj.apply(args[0], [...rest, ...args2]);
    };
  };
  
  const moses = printOutMyName.myBinding(name, "SDE", "130,000", "Male");
  moses("amazing");