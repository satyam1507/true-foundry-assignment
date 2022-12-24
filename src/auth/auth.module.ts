/* eslint-disable prettier/prettier */
import { AuthController } from './auth.controller';
import { Module } from '@nestjs/common';
import { GithubStrategy } from './strategy';
import { AuthService } from './auth.service';

@Module({
    controllers: [AuthController],
    providers: [GithubStrategy,AuthService],
})
export class AuthModule {}
