Js.log("Hello, BuckleScript and Reason!");

[@bs.module "../config.json"] external token: string = "token";
[@bs.module "../config.json"] external prefix: string = "prefix";

open Discord;
let client = Client.createClient();

Client.onReady(
  client,
  _ => {
    Js.log("Bot is ready");
    Client.user(client)->ClientUser.setActivity("Proving spyder doesn't know discord");
  },
);

let handleMessage = msg => {
  let command =
    (Js.String.substr(Message.content(msg), ~from=1) |> Js.String.split(" "))
    ->Belt.List.fromArray;
  switch (command) {
  | ["ping", ..._] => Message.reply(msg, "pong")
  | _ => () // TODO
  };
};

// immediate filter to ignore bot messages
Client.onMessage(client, msg =>
  switch (
    Message.author(msg)->User.bot,
    Message.content(msg) |> Js.String.indexOf(prefix),
    Message.channel(msg)->Channel.name,
  ) {
  | (false, 0, "spyder-reasonml") => handleMessage(msg)
  | _ =>
    // this will quickly get spammy hahaha
    Js.logMany([|
      "Unhandled message, from: ",
      Message.author(msg)->User.name,
      "\nChannel: ",
      Message.channel(msg)->Channel.name,
      "\nContents:\n",
      Message.content(msg),
      "------",
    |])
  }
);

Client.login(client, token);