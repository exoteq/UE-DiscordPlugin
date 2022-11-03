# UE-DiscordPlugin
UE5 Discord Plugin which makes use of the discord chat in UE Games

## Preview
- https://youtu.be/-88IccrNFuI

## Features
- Get messages from a defined discord channel
- Push messages to a defined discord channel
- differ between ingame and discord messages

## Requirements
- Create a discord server (https://support.discord.com/hc/en-us/articles/204849977-How-do-I-create-a-server-)


## Installation
- Go to your browser and open: https://discord.com/login
- Use your account or create a new one
- Create a new application (https://discord.com/developers/applications)
- Open "Bot" in the left sidebar
- Create a new Bot by clicking on "Add Bot"
- Reset your Bot token (save that token for later)
- toggle: "Required for your bot to receive message content in most messages"
- Open OAuth2->URL Generator and tick "bot" for scores and "Send Messages", "Read Messages/View Channels" for Bot Permissions
- Open the generated url and select your server, then click authorize
- Open your discord server and create and open a channel which u will later use for that chat
- You will find the channel ID in the URL: https://discord.com/channels/<serverID>/<channelID>
- Now you should have the bot token and channelID
- Open the project, then the WB_Chat Blueprint
- Search for the variables "token", "channelID" and add your informations then start the game in the editor