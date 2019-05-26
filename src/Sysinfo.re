open Discord;

[@bs.module "process"] external platform: string = "platform";

[@bs.module "os"] external releaseF: unit => string = "release";
let release = releaseF();

[@bs.module "os"] external uptimeF: unit => int = "uptime";
let uptime = uptimeF() / 3600 / 24;

[@bs.module "os"] external totalmemF: unit => int = "totalmem";
let totalmem = totalmemF() / 1048576 / 1024;

[@bs.module "os"] external freememF: unit => int = "freemem";
let freemem = freememF() / 1048576 / 1024;

let info = {j|
OS codename: $platform version $release
Uptime: $uptime days
Memory: $freemem / $totalmem GB
Storage: plenty 😂
|j}

Js.log2("sys info", info);

let richInfo = () => {
  open RichEmbed;
  create()
  ->title("Spyder's bot hosting system")
  ->color("DARK_PURPLE")
  ->description(info);
};