import asyncio
import websockets
import serial

# Configurações da porta serial do Arduino
arduino_port = 'COM6'  # Substitua pelo nome da porta correta
baud_rate = 9600
arduino = serial.Serial(arduino_port, baud_rate)

async def handler(websocket, path):
    async for message in websocket:
        print(f"Received message: {message}")
        arduino.write(f"{message}\n".encode())

        # Enviar resposta de volta para o cliente (opcional)
        # response = f"Command {message} sent to Arduino"
        # await websocket.send(response)

start_server = websockets.serve(handler, "localhost", 8765)

asyncio.get_event_loop().run_until_complete(start_server)
asyncio.get_event_loop().run_forever()
