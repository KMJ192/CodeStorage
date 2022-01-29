function getMessage(message: string) {
  return new Promise((resolve, reject) => {
    resolve(`1. ${message}`);
  });
}

async function showMessage() {
  getMessage("message").then((message) => console.log(`2. ${message}`));

  const message = await getMessage("message2");
  console.log(`3. ${message}`);
}

function run() {
  showMessage();
}

export default run;
