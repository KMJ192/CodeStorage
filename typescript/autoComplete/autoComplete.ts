function autoComplete() {
  const tmp: Set<string> = new Set();

  tmp.add("app");
  tmp.add("apple");
  tmp.add("append");
  tmp.add("한");
  tmp.add("한글");
  tmp.add("한글 자동완성");

  tmp.forEach((value: string) => {
    console.log(value);
  });
}

export default autoComplete;
