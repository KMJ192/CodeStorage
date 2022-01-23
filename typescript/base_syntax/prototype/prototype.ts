// declare global {
//   interface machine {
//     // q: string;
//     // w: string;
//   }
// }

function machine(): void {
  this.q = "strike";
  this.w = "snowball";
}

function pt() {
  machine.prototype.name = "kim";
  const nunu = new machine();
  console.log(nunu.name);
}

export default pt;
