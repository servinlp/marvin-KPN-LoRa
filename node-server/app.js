const express = require( 'express' ),
	app = express(),
	ejs = require( 'ejs' ),
	bodyParser = require( 'body-parser' ),
	obj = [],
	PORT = 8003

app.use( bodyParser.urlencoded({ extended: false }) )
app.use( bodyParser.json() )

app.set( 'view engine', 'ejs' )
app.set( 'views', './views' )

app.get( '/', ( req, res ) => {

	res.render( 'index', { messages: obj })

})

app.post( '/entries', ( req, res ) => {

	obj.push( req.body.DevEUI_uplink.payload_hex )

	res.writeHead( 200, { 'Content-Type': 'application/json' })

	const json = JSON.stringify({
		succes: true
	})

	res.end( json )

})

app.listen( PORT, () => {

	console.log( `Hello from ${PORT}` )

})
