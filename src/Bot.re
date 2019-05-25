Js.log("Hello, BuckleScript and Reason!");

[@bs.module "../../../config.json"] external token : string = "token";
[@bs.module "../../../config.json"] external prefix : string = "prefix";

open Discord;
let client = Client.createClient();

Client.onReady(client, _ => {
  Js.log("Bot is ready");
  Client.user(client) -> ClientUser.setActivity("Proving spyder doesn't know discord")
});

let handleMessage = msg =>
  switch (Message.content(msg)) {
  | "ping" => Message.reply(msg, "pong")
  | _ => () // TODO
  };

// immediate filter to ignore bot messages
Client.onMessage(client, msg => Message.author(msg) -> User.bot ? () : handleMessage(msg));

Client.login(client, token);