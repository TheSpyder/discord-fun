open Discord;

let swearList = ["fuck", "shit", "cunt", "arse"];

let swearRegexStr = String.concat("|", swearList);

let swearRegex = () => Js.Re.fromStringWithFlags(swearRegexStr, ~flags="ig");

let rec spiders =
  fun
  | 0 => ""
  | x => ":spider:" ++ spiders(x - 1);

let filterMessage = Js.String.unsafeReplaceBy0(swearRegex(), (match, _, _) => {
  Js.String.charAt(0, match) ++ spiders(String.length(match) - 1);
})

// Js.log2("regex test: ", filterMessage("that's fucking bullshit"));

let swears = msg => {
  let content = Message.content(msg);
  let censoredMessage = filterMessage(content);
  if (censoredMessage != content) {
    Js.log2("Filtering message", content);
    let channel = Message.channel(msg);
    let author = Message.author(msg)->User.name;
    Channel.send(channel, {j|**$author**: $censoredMessage|j});
    Message.delete(msg);
  };
};